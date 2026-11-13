; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x709406 (bvmul arg0_21 arg2_8)))
(let ((?x711025 (bvmul (_ bv4294967295 32) ?x709406)))
(let ((?x17831 (bvmul arg0_21 arg2_7)))
(let ((?x331716 (bvadd ?x17831 ?x711025)))
(and (distinct ?x331716 (_ bv0 32)) true))))))
(check-sat)
