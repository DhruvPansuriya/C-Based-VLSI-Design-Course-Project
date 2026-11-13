; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x39935 (bvmul arg0_21 arg2_8)))
(let ((?x710986 (bvmul (_ bv4294967295 32) ?x39935)))
(let ((?x5020 (bvmul arg0_21 arg2_7)))
(let ((?x721960 (bvadd ?x5020 ?x710986)))
(and (distinct ?x721960 (_ bv0 32)) true))))))
(check-sat)
