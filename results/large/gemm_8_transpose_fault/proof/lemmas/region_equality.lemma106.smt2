; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_58 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_23 () (_ BitVec 32))
(assert
 (let ((?x72903 (bvmul arg0_10 arg1_58)))
(let ((?x6301 (bvmul (_ bv4294967295 32) ?x72903)))
(let ((?x57 (bvmul arg0_10 arg1_23)))
(let ((?x70858 (bvadd ?x57 ?x6301)))
(and (distinct ?x70858 (_ bv0 32)) true))))))
(check-sat)
