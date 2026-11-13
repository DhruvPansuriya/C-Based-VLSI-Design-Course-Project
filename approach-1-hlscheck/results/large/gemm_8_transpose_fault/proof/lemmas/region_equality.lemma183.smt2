; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_16 () (_ BitVec 32))
(declare-fun arg0_24 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x72924 (bvmul arg0_24 arg1_16)))
(let ((?x55983 (bvmul (_ bv4294967295 32) ?x72924)))
(let ((?x31432 (bvmul arg0_24 arg1_2)))
(let ((?x57831 (bvadd ?x31432 ?x55983)))
(and (distinct ?x57831 (_ bv0 32)) true))))))
(check-sat)
