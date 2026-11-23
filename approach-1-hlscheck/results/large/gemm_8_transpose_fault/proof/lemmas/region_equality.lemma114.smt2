; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_16 () (_ BitVec 32))
(assert
 (let ((?x72919 (bvmul arg0_18 arg1_2)))
(let ((?x60408 (bvmul (_ bv4294967295 32) ?x72919)))
(let ((?x63798 (bvmul arg0_18 arg1_16)))
(let ((?x57485 (bvadd ?x63798 ?x60408)))
(and (distinct ?x57485 (_ bv0 32)) true))))))
(check-sat)
